# $NetBSD: Makefile,v 1.1 1998/08/25 12:53:07 agc Exp $
#

DISTNAME=	scilab-2.4-src
PKGNAME=	scilab-2.4
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/

MAINTAINER=	mcmahill@alum.mit.edu
HOMEPAGE=	http://www-rocq.inria.fr/scilab/

WRKSRC=		${WRKDIR}/${PKGNAME}

DEPENDS+=	f2c-19980516p1:../../lang/f2c
DEPENDS+=	xless-1.7:../../x11/xless

USE_X11=	yes
GNU_CONFIGURE=	yes

PLIST_SRC=	${WRKDIR}/PLIST-src

MAKE_ENV+=	HOME=${WRKSRC}

post-install:
	@bigopsys=`${ECHO} ${OPSYS} | tr '[a-z]' '[A-Z]'`;	\
	bigarch=`${ECHO} ${MACHINE_ARCH} | tr '[a-z]' '[A-Z]'`;	\
	${SED} -e 's|\$${OPSYS}|'$$bigopsys'|g' 		\
		-e 's|\$${MACHINE_ARCH}|'$$bigarch'|g'		\
		${PKGDIR}/PLIST > ${PLIST_SRC}
	@${ECHO} "******************************************************************************"
	@${ECHO} 0 - COPYRIGHT NOTICE
	@${ECHO}
	@${ECHO} To use Scilab, you need to fill and return the end of the file notice.tex
	@${ECHO} "or notice.ps (postscript file). You may email to Scilab@inria.fr."
	@${ECHO} "These files are in ${PREFIX}/share/scilab-2.4/"
	@${ECHO} "******************************************************************************"

.include "../../mk/bsd.pkg.mk"
