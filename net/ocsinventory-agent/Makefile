# $NetBSD: Makefile,v 1.18 2018/08/22 09:45:56 wiz Exp $
#
VERS=			1.1.2.1
PKGREVISION=		10
DISTNAME=		Ocsinventory-Agent-${VERS}
PKGNAME=		ocsinventory-agent-${VERS}
CATEGORIES=		net
MASTER_SITES=		http://launchpad.net/ocsinventory-unix-agent/stable-1.1.2/ocsinventory-unix-agent-1.1.2.1/+download/
MASTER_SITES+=		http://launchpadlibrarian.net/57513674/

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		http://www.ocsinventory-ng.org/
COMMENT=		Keep track of the computers configuration and software

PKG_SYSCONFSUBDIR=	ocsinventory

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=		p5-Net-IP-[0-9]*:../../net/p5-Net-IP
DEPENDS+=		p5-Proc-Daemon-[0-9]*:../../devel/p5-Proc-Daemon
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
DEPENDS+=		dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

WRKSRC=			${WRKDIR}/Ocsinventory-Agent-${VERS}

BUILD_DEFS+=		VARBASE
AUTO_MKDIRS=yes

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/ocsinventory-agent
MAKE_DIRS_PERMS+=	${VARBASE}/db/ocsinventory ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
CONF_FILES+=		${EGDIR}/ocsinventory-agent.cfg ${PKG_SYSCONFDIR}/ocsinventory-agent.cfg
CONF_FILES+=		${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf

USE_TOOLS+=	perl:run
REPLACE_PERL+=	tools/macosx/ocsng_app-xcode/main.pl
REPLACE_PERL+=	tools/macosx/scripts/create-darwin-perl-lib_fromCPAN.pl
REPLACE_PERL+=	ocsinventory-agent
REPLACE_PERL+=	postinst.pl

SUBST_CLASSES+=			sysconfdir path varbase apachevers
SUBST_STAGE.sysconfdir=		pre-configure
SUBST_FILES.sysconfdir=		lib/Ocsinventory/Agent/Config.pm
SUBST_FILES.sysconfdir+=	postinst.pl
SUBST_SED.sysconfdir=		-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_MESSAGE.sysconfdir=	Fixing hardcoded install directory path.

SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	lib/Ocsinventory/Agent/Common.pm
SUBST_SED.path=		-e "s|/usr/local/bin|${PREFIX}/bin|g"
SUBST_SED.path+=	-e "s|/usr/local/sbin|${PREFIX}/sbin|g"
SUBST_MESSAGE.path=	Fixing hardcoded path.

PERL5_PACKLIST=		auto/Ocsinventory/Agent/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

pre-patch:
	${MKDIR} ${WRKSRC}/lib/Ocsinventory/Agent/Backend/OS/BSD/Pcictl

post-patch:
	${FIND} ${WRKSRC} -perm 0 -print | ${XARGS} ${CHMOD} +rw

post-build:
	for file in ocsinventory-agent.cfg modules.conf; do \
		${SED} -e 's,@VARBASE@,${VARBASE},g' \
		    < ${FILESDIR}/$$file > ${WRKDIR}/$$file; \
	done

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for file in ocsinventory-agent.cfg modules.conf; do \
		${INSTALL_DATA} ${WRKDIR}/$$file ${DESTDIR}${EGDIR}; \
	done
	cd ${DESTDIR}${PREFIX}/bin && \
	    ${LN} -f -s ${PERL5_INSTALLVENDORBIN}/ocsinventory-agent .

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
