# $NetBSD: Makefile,v 1.5 2009/08/30 21:57:07 tonnerre Exp $

DISTNAME=		puppet-0.24.7
PKGREVISION=		1
CATEGORIES=		sysutils

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.reductivelabs.com/projects/puppet/
MASTER_SITE=		http://reductivelabs.com/downloads/gems/
COMMENT=		Configuration management framework written in Ruby

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		${RUBY_PKGPREFIX}-facter>=1.3.8:../../sysutils/ruby-facter

GEM_BUILD=		gemspec

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	lib/puppet/reference/configuration.rb
SUBST_FILES.prefix+=	lib/puppet/defaults.rb spec/unit/util/selinux.rb
SUBST_FILES.prefix+=	bin/puppetrun bin/puppet bin/puppetdoc
SUBST_FILES.prefix+=	ext/puppetstoredconfigclean.rb ext/puppetlast
SUBST_FILES.prefix+=	examples/puppetmasterd.conf man/man8/puppet.8
SUBST_FILES.prefix+=	conf/solaris/smf/puppetd.xml
SUBST_FILES.prefix+=	conf/solaris/smf/puppetmasterd.xml
SUBST_FILES.prefix+=	man/man8/puppetrun.8 man/man8/puppet.conf.8
SUBST_SED.prefix=	-e "s|/etc/puppet|${PKG_SYSCONFDIR}|g"
SUBST_SED.prefix+=	-e "s|/opt/csw/lib|${PREFIX}/lib|g"

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/puppet.conf ${PKG_SYSCONFDIR}/puppet.conf

PLIST_VARS+=		sunos

.if ${OPSYS} == "SunOS"
INSTALLATION_DIRS=	lib/svc/method ${EGDIR}/svc
CONF_DIR+=		${VARBASE}/svc/manifest
CONF_FILES+=		${EGDIR}/svc/puppetd.xml ${VARBASE}/svc/manifest/puppetd.xml
CONF_FILES+=		${EGDIR}/svc/puppetmasterd.xml ${VARBASE}/svc/manifest/puppetmasterd.xml
PLIST.sunos=		yes
.endif

pre-build:
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppetmasterd			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppet.conf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/puppet.conf			\
		${DESTDIR}${EGDIR}
.if ${OPSYS} == "SunOS"
	${INSTALL_DATA} ${WRKSRC}/conf/solaris/smf/puppetd.xml		\
		${DESTDIR}${EGDIR}/svc
	${INSTALL_DATA} ${WRKSRC}/conf/solaris/smf/puppetmasterd.xml	\
		${DESTDIR}${EGDIR}/svc
	${INSTALL_SCRIPT} ${WRKSRC}/conf/solaris/smf/svc-puppetd	\
		${DESTDIR}${PREFIX}/lib/svc/method
	${INSTALL_SCRIPT} ${WRKSRC}/conf/solaris/smf/svc-puppetmasterd	\
		${DESTDIR}${PREFIX}/lib/svc/method
.endif

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
