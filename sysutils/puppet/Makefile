# $NetBSD: Makefile,v 1.16 2014/01/01 23:46:38 tonnerre Exp $

DISTNAME=		puppet-3.1.1
PKGREVISION=		1
CATEGORIES=		sysutils
#MASTER_SITES=		http://puppetlabs.com/downloads/puppet/

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://www.puppetlabs.com/
COMMENT=		Configuration management framework written in Ruby
LICENSE=		gnu-gpl-v2

DEPENDS+=		${RUBY_PKGPREFIX}-facter>=1.6.18:../../sysutils/ruby-facter
DEPENDS+=		${RUBY_PKGPREFIX}-hiera>=1.0.0:../../databases/ruby-hiera
DEPENDS+=		${RUBY_PKGPREFIX}-io-console>=0.3:../../devel/ruby-io-console
DEPENDS+=		${RUBY_PKGPREFIX}-json-pure>=0:../../textproc/ruby-json-pure
DEPENDS+=		${RUBY_PKGPREFIX}-minitest>=2.5.1:../../devel/ruby-minitest
DEPENDS+=		${RUBY_PKGPREFIX}-shadow>=2.0.0:../../security/ruby-shadow

RUBY_VERSION_SUPPORTED=	193

CONFLICTS+=		ruby[1-9][0-9]-puppet-[0-9]* puppet-[0-9]*

PKG_SYSCONFSUBDIR=	puppet
RCD_SCRIPTS=		puppetd puppetmasterd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	install.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/changes.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/install.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/list.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/uninstall.rb
SUBST_FILES.prefix+=	lib/puppet/face/module/upgrade.rb
SUBST_FILES.prefix+=	lib/puppet/parser/functions/extlookup.rb
SUBST_FILES.prefix+=	lib/puppet/reference/configuration.rb
SUBST_FILES.prefix+=	lib/puppet/defaults.rb lib/puppet/util/run_mode.rb
SUBST_FILES.prefix+=	bin/puppet ext/rack/manifest.pp
SUBST_FILES.prefix+=	ext/rack/files/apache2.conf ext/rack/files/config.ru
SUBST_FILES.prefix+=	ext/solaris/smf/puppetd.xml
SUBST_FILES.prefix+=	ext/solaris/smf/puppetmasterd.xml
SUBST_FILES.prefix+=	man/man5/puppet.conf.5
SUBST_FILES.prefix+=	man/man8/puppet.8
SUBST_FILES.prefix+=	man/man8/puppet-apply.8
SUBST_FILES.prefix+=	man/man8/puppet-device.8
SUBST_FILES.prefix+=	man/man8/puppet-doc.8
SUBST_FILES.prefix+=	man/man8/puppet-module.8
SUBST_FILES.prefix+=	man/man8/puppet-parser.8
SUBST_FILES.prefix+=	spec/unit/util/run_mode_spec.rb
SUBST_FILES.prefix+=	spec/unit/util/selinux_spec.rb
SUBST_FILES.prefix+=	spec/unit/indirector/catalog/static_compiler_spec.rb
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
		${FIND} lib/puppet spec -type f -exec ${CHMOD} -x {} \;
	cd ${WRKSRC} && ${RUBY} -Ilib bin/puppet agent			\
		--confdir=${PKG_SYSCONFDIR:Q} --rundir=${VARBASE:Q}/run	\
		--genconfig |						\
		${SED} -e 's/genconfig = true/# genconfig = false/'	\
		> examples/puppet.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/puppet.conf			\
		${DESTDIR}${PREFIX}/${EGDIR}
.if ${OPSYS} == "SunOS"
	${INSTALL_DATA} ${WRKSRC}/ext/solaris/smf/puppetd.xml		\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_DATA} ${WRKSRC}/ext/solaris/smf/puppetmasterd.xml	\
		${DESTDIR}${PREFIX}/${EGDIR}/svc
	${INSTALL_SCRIPT} ${WRKSRC}/ext/solaris/smf/svc-puppetd		\
		${DESTDIR}${PREFIX}/lib/svc/method
	${INSTALL_SCRIPT} ${WRKSRC}/ext/solaris/smf/svc-puppetmasterd	\
		${DESTDIR}${PREFIX}/lib/svc/method
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
