# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:14 tv Exp $
#

DISTNAME=	eggdrop1.6.15
PKGNAME=	${DISTNAME:S/eggdrop/eggdrop-/}
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=	http://www.eggheads.org/
COMMENT=	IRC robot with TCL scripting and multi-channel ability

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		TCLLIB="${PREFIX}/lib" TCLINC="${PREFIX}/include"

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
BUILD_DEFS+=		USE_INET6
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUBST+=		NOIPV6="@comment "
.else
PLIST_SUBST+=		NOIPV6=
.endif

EGDIR=		${PREFIX}/share/examples/eggdrop
CONF_FILES=	${EGDIR}/eggdrop.conf ${PKG_SYSCONFDIR}/eggdrop.conf

post-patch:
	cd ${WRKSRC} && ${SED} -e 's,modules/,${PREFIX}/lib/eggdrop/,' \
		< eggdrop.conf > eggdrop.conf.dist.new

post-configure:
	cd ${WRKSRC} && ${MAKE} config

do-install: do-install-program
do-install-program:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.dist.new ${EGDIR}/eggdrop.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/eggdrop
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html \
		${PREFIX}/share/doc/html/eggdrop
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/eggdrop
	cd ${WRKSRC}/doc && ${INSTALL_DATA} BANS BOTNET MODULES PARTYLINE \
		USERS first_script.txt tcl-commands.doc text-substitutions.doc \
		tricks ${PREFIX}/share/doc/eggdrop
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop/help
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop/language
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop/scripts
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop/help/msg
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop/help/set
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang \
		${PREFIX}/share/eggdrop/language/
	cd ${WRKSRC}/help && ${INSTALL_DATA} cmds1.help cmds2.help core.help \
		${PREFIX}/share/eggdrop/help/
	cd ${WRKSRC}/help/set && ${INSTALL_DATA} cmds1.help \
		${PREFIX}/share/eggdrop/help/set/
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS *.tcl autobotchk \
		 botchk weed ${PREFIX}/share/eggdrop/scripts/

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if defined(NOPIC)
ALL_TARGET=	static
PLIST_SUBST+=	NOPIC="@comment "
.else
PLIST_SUBST+=	NOPIC=
do-install: do-install-modules
do-install-modules:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/eggdrop
	cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
		compress.so console.so ctcp.so filesys.so irc.so notes.so \
		seen.so server.so share.so transfer.so uptime.so wire.so \
		${PREFIX}/lib/eggdrop
.if !defined(USE_INET6) || empty(USE_INET6:M[Yy][Ee][Ss])
	cd ${WRKSRC} && ${INSTALL_DATA} dns.so ${PREFIX}/lib/eggdrop
.endif
	cd ${WRKSRC}/src/mod && ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} "{}" \
		${PREFIX}/share/eggdrop/language ";"
.endif
