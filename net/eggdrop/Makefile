# $NetBSD: Makefile,v 1.9 2002/06/25 14:16:15 kent Exp $
#

DISTNAME=	eggdrop1.6.10
PKGNAME=	eggdrop-1.6.10
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/

MAINTAINER=     tv@netbsd.org
HOMEPAGE=	http://www.eggheads.org/
COMMENT=	IRC robot with TCL scripting and multi-channel ability

DEPENDS+=	tcl>=8.3.2:../../lang/tcl

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	TCLLIB="${PREFIX}/lib" TCLINC="${PREFIX}/include"

post-patch:
	cd ${WRKSRC} && ${SED} -e 's,modules/,${PREFIX}/lib/eggdrop/,' \
		< eggdrop.complete.conf > eggdrop.conf.dist.new

post-configure:
	cd ${WRKSRC} && ${MAKE} config

do-install: do-install-program
do-install-program:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.dist.new ${PREFIX}/etc/eggdrop.conf.dist
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop \
		${PREFIX}/share/eggdrop/help ${PREFIX}/share/eggdrop/language \
		${PREFIX}/share/eggdrop/scripts ${PREFIX}/share/eggdrop/html \
		${PREFIX}/share/eggdrop/help/msg ${PREFIX}/share/eggdrop/help/set
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang \
		${PREFIX}/share/eggdrop/language/
	cd ${WRKSRC}/doc && ${INSTALL_DATA} BOTNET tcl-commands.doc tricks \
		${PREFIX}/share/eggdrop/
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html ${PREFIX}/share/eggdrop/html
	cd ${WRKSRC}/help && ${INSTALL_DATA} cmds1.help cmds2.help core.help \
		${PREFIX}/share/eggdrop/help/
	cd ${WRKSRC}/help/set && ${INSTALL_DATA} cmds1.help cmds2.help \
		${PREFIX}/share/eggdrop/help/set/
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS action.fix.tcl \
		autobotchk alltools.tcl botchk cmd_resolve.tcl compat.tcl getops.tcl \
		klined.tcl notes2.tcl ques5.tcl sentinel.tcl userinfo.tcl weed \
		${PREFIX}/share/eggdrop/scripts/

.include "../../mk/bsd.pkg.mk"

.if defined(NOPIC)
ALL_TARGET=	static
.else
do-install: do-install-modules
do-install-modules:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/eggdrop
	cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
		compress.so console.so ctcp.so dns.so filesys.so irc.so notes.so seen.so \
		server.so share.so transfer.so uptime.so wire.so \
		${PREFIX}/lib/eggdrop/
.endif
