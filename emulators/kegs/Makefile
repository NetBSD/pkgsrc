# $NetBSD: Makefile,v 1.8 2013/12/10 14:10:14 jperkin Exp $
#

DISTNAME=	kegs.0.91
PKGNAME=	kegs-0.91
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://kegs.sourceforge.net/

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://kegs.sourceforge.net/
COMMENT=	Apple IIgs emulator for Mac OS X, Win32, Linux, and Unix/X11

# Official support
ONLY_FOR_PLATFORM=	Linux-*-i386 Linux-*-powerpc SunOS-*-i386 SunOS-*-sparc Darwin-*-* HPUX-*-*
# Probably work
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-powerpc *-*-x86_64 *-*-ia64 *-*-mips *-*-m68k

#WRKSRC=		${WRKDIR}/${DISTNAME}/src
CONFIGURE_DIRS=	src
BUILD_DIRS=	src
USE_TOOLS+=     gmake perl
INSTALLATION_DIRS+=	bin share/doc/${PKGBASE} share/${PKGBASE}

# Has problems finding shared libs on some platforms...
CFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib

LIBS.SunOS+=	-lsocket -lnsl

pre-build:
	if [ -L ${WRKSRC}/src/vars ]; then ${RM} ${WRKSRC}/src/vars; fi
	@${ECHO} Building for ${OPSYS} on ${MACHINE_ARCH}...
	case "${OPSYS}_${MACHINE_ARCH}" in				\
	Linux_ppc) ${LN} -s ${WRKSRC}/src/vars_linuxppc ${WRKSRC}/src/vars; break;;\
	Linux_i386) ${LN} -s ${WRKSRC}/src/vars_x86linux ${WRKSRC}/src/vars; break;;\
	SunOS_sparc*) ${LN} -s ${WRKSRC}/src/vars_solaris ${WRKSRC}/src/vars; break;;\
	SunOS_i386) ${LN} -s ${WRKSRC}/src/vars_x86solaris ${WRKSRC}/src/vars; break;;\
	SunOS_x86_64) ${LN} -s ${WRKSRC}/src/vars_x86solaris ${WRKSRC}/src/vars; break;;\
	Darwin*) ${LN} -s ${WRKSRC}/src/vars_mac ${WRKSRC}/src/vars; break;;	\
	HPUX*) ${LN} -s ${WRKSRC}/src/vars_hp ${WRKSRC}/src/vars; break;;	\
	*_i386) ${ECHO} "${OPSYS} on ${MACHINE_ARCH} is not officially supported, but ought to work..."; ${LN} -s ${WRKSRC}/src/vars_x86linux ${WRKSRC}/src/vars; break;;\
	*_ppc|*_powerpc) ${ECHO} "${OPSYS} on ${MACHINE_ARCH} is not officially supported, but ought to work..."; ${LN} -s ${WRKSRC}/src/vars_linuxppc ${WRKSRC}/src/vars; break;;\
	*_amd64|*_ia64|*_x86_64) ${ECHO} "${MACHINE_ARCH} is not supported, but might work..."; ${LN} -s ${WRKSRC}/src/vars_x86linux ${WRKSRC}/src/vars; break;;\
	*_mips|*_m68k) ${ECHO} "${MACHINE_ARCH} is not supported, but might work..."; ${LN} -s ${WRKSRC}/src/vars_linuxppc ${WRKSRC}/src/vars; break;;\
	*) ${ECHO} Your platform is not recognized. ;;			\
	esac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkegs ${DESTDIR}${PREFIX}/bin/xkegs
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/config.kegs ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
