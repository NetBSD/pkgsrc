# $NetBSD: Makefile,v 1.24 2006/07/27 18:48:02 jlam Exp $
#
PEACE_VERSION=	0.0.20060701
DISTNAME=	peace-${PEACE_VERSION}
SITES.peace-0.0.20060701.tar.gz=http://chiharu.hauN.org/peace/dist/
CATEGORIES=	emulators

MAINTAINER=	kent@NetBSD.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Support running Win32 executables

DISTFILES+=	peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
ONLY_FOR_PLATFORM=      NetBSD-[2-9]*-i386
DEPENDS+=	icu>=2.4nb1:../../textproc/icu
DEPENDS+=	freetype2>=2.2.1:../../graphics/freetype2
# bin/showstack requires perl5 and cross-i386-netbsdpe
# DEPENDS+=	perl5:../../lang/perl5
# DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe

BUILD_DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	x11-links>=0.30:../../pkgtools/x11-links

# Don't use "+=" here to avoid unexpected link with ELF libraries
LDFLAGS=	-L${WRKSRC}/lib
PECOFFDIR=	${PREFIX}/emul/pecoff
MAKE_FLAGS+=	PECOFFDIR=${PECOFFDIR:Q} \
		LOCALBASE=${LOCALBASE:Q} \
		CROSSBASE=${CROSSBASE:Q} \
		X11BASE=${X11BASE:Q} \
		CHECK_DEPENDENTS=NO

INSTALL_DIRS=	libexec/ld.pe_so dll bin

pre-install:
	${INSTALL_PROGRAM_DIR} ${PECOFFDIR}/usr/libexec
	${INSTALL_DATA_DIR} ${PECOFFDIR}/usr/lib

post-install:
	${RMDIR} ${PREFIX}/emul/pecoff/usr/share/man/cat1
	${RMDIR} ${PREFIX}/emul/pecoff/usr/share/man/man1
	${RMDIR} ${PREFIX}/emul/pecoff/usr/share/man
	${RMDIR} ${PREFIX}/emul/pecoff/usr/share

.include "../../mk/bsd.pkg.mk"
