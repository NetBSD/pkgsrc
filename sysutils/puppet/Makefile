# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:20 asau Exp $

DISTNAME=		puppet-0.25.5
PKGREVISION=		1
CATEGORIES=		sysutils
#MASTER_SITES=		http://puppetlabs.com/downloads/puppet/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.puppetlabs.com/
COMMENT=		Configuration management framework written in Ruby
LICENSE=		gnu-gpl-v2

DEPENDS+=		${RUBY_PKGPREFIX}-facter>=1.3.8:../../sysutils/ruby-facter

CONFLICTS+=		ruby[1-9][0-9]-puppet-[0-9]* puppet-[0-9]*

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	lib/puppet/reference/configuration.rb
SUBST_FILES.prefix+=	lib/puppet/defaults.rb spec/unit/util/selinux.rb
SUBST_FILES.prefix+=	bin/puppetrun bin/puppet bin/puppetdoc
SUBST_FILES.prefix+=	ext/puppetstoredconfigclean.rb ext/puppetlast
SUBST_FILES.prefix+=	man/man8/puppet.8
SUBST_FILES.prefix+=	conf/solaris/smf/puppetd.xml
SUBST_FILES.prefix+=	conf/solaris/smf/puppetmasterd.xml
SUBST_FILES.prefix+=	man/man8/puppetrun.8 man/man8/puppet.conf.8
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"
SUBST_SED.prefix+=	-e "s|/opt/csw/lib|${PREFIX}/lib|g"

EGDIR=			share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/puppet.conf ${PKG_SYSCONFDIR}/puppet.conf

## Since these users are needed only for puppet server,
## puppet-server package should be created.
#SUBST_CLASSES+=		user
#SUBST_STAGE.user=	post-patch
#SUBST_FILES.user=	lib/puppet/defaults.rb
#SUBST_SED.user=		-e "s|@PUPPET_GROUP@|${PUPPET_GROUP}|g"
#SUBST_SED.user+=	-e "s|@PUPPET_USER@|${PUPPET_USER}|g"
#
#PKG_GROUPS_VARS=		PUPPET_GROUP
#PKG_USERS_VARS=			PUPPET_USER
#
#PKG_GROUPS=			${PUPPET_GROUP}
#PKG_USERS=			${PUPPET_USER}:${PUPPET_GROUP}
#PKG_GECOS.${PUPPET_USER}=       Puppet configuration management pseudo-user

PLIST_SUBST+=		EGDIR=${EGDIR}
PLIST_VARS+=		sunos

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.prefs.mk"

#PUPPET_GROUP?=		puppet
#PUPPET_USER?=		puppet

.if ${OPSYS} == "SunOS"
INSTALLATION_DIRS+=	lib/svc/method ${EGDIR}/svc
CONF_DIRS+=		${VARBASE}/svc/manifest
CONF_FILES+=		${EGDIR}/svc/puppetd.xml ${VARBASE}/svc/manifest/puppetd.xml
CONF_FILES+=		${EGDIR}/svc/puppetmasterd.xml ${VARBASE}/svc/manifest/puppetmasterd.xml
PLIST.sunos=		yes
.endif

pre-build:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${CHMOD} g-w {} \;
	cd ${WRKSRC} && \
		${FIND} lib/puppet spec test -type f -exec ${CHMOD} -x {} \;
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppetmasterd			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppet.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/puppet.conf			\
		${DESTDIR}${PREFIX}/${EGDIR}
.if ${OPSYS} == "SunOS"
	${INSTALL_DATA} ${WRKSRC}/conf/solaris/smf/puppetd.xml		\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_DATA} ${WRKSRC}/conf/solaris/smf/puppetmasterd.xml	\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_SCRIPT} ${WRKSRC}/conf/solaris/smf/svc-puppetd	\
		${DESTDIR}${PREFIX}/lib/svc/method
	${INSTALL_SCRIPT} ${WRKSRC}/conf/solaris/smf/svc-puppetmasterd	\
		${DESTDIR}${PREFIX}/lib/svc/method
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
