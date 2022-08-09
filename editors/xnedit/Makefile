# $NetBSD: Makefile,v 1.7 2022/08/09 12:08:30 jperkin Exp $

DISTNAME=	xnedit-1.4.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xnedit/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/xnedit/
COMMENT=	Fork of NEdit with Unicode support and antialiased text
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99
USE_TOOLS=	pkg-config yacc

WRKSRC=			${WRKDIR}/xnedit
BUILD_TARGET=		generic
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PREFIX}/share/doc/xnedit

# Use POSIX struct dirent (instead of BSD struct direct)
CFLAGS+=	-DUSE_DIRENT
# Workaround for bugs in IRIX Motif library
CFLAGS.IRIX+=	-DNO_XMIM
# Workaround for bugs in Solaris Motif library
CFLAGS.SunOS+=	-DROWCOLPATCH

LDFLAGS.Darwin+=	-liconv

# Honor external CFLAGS
SUBST_CLASSES+=			fix-cflags
SUBST_STAGE.fix-cflags=		pre-configure
SUBST_MESSAGE.fix-cflags=	Fixing Makefile.generic.
SUBST_FILES.fix-cflags=		makefiles/Makefile.generic
SUBST_SED.fix-cflags=		-e 's,CFLAGS=,CFLAGS+=,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/xnedit ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/source/xnc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xnedit.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnedit.1
	${INSTALL_MAN} ${WRKSRC}/doc/xnc.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xnc.1
.for f in README.md ReleaseNotes
	 ${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/xnedit
.endfor
.for f in NEdit.ad faq.txt xnedit.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/doc/xnedit
.endfor

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
