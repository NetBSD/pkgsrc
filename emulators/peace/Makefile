# $NetBSD: Makefile,v 1.21 2006/03/10 13:57:13 kent Exp $
#
PEACE_VERSION=	0.0.20060310
DISTNAME=	peace-${PEACE_VERSION}
SITES_peace-0.0.20060310.tar.gz=http://chiharu.hauN.org/peace/dist/
CATEGORIES=	emulators

MAINTAINER=	kent@NetBSD.org
HOMEPAGE=	http://chiharu.hauN.org/peace/
COMMENT=	Support running Win32 executables

DISTFILES+=	peace-${PEACE_VERSION}.tar.gz
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=peace/}
ONLY_FOR_PLATFORM=      NetBSD-[2-9]*-i386
DEPENDS+=	icu>=2.4nb1:../../textproc/icu
# bin/showstack requires perl5 and cross-i386-netbsdpe
# DEPENDS+=	perl5:../../lang/perl5
# DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe

BUILD_DEPENDS+=	cross-i386-netbsdpe>=3.3:../../cross/i386-netbsdpe
BUILD_DEPENDS+=	w32api>=2.5:../../devel/w32api

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

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
