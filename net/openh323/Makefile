# $NetBSD: Makefile,v 1.1.1.1 2000/08/25 16:11:14 mjl Exp $
#

DISTNAME=	openh323_1.1beta3
PKGNAME=	openh323-1.1beta3
CATEGORIES=	net
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.au.openh323.org/bin/ \
		http://www.au2.openh323.org/bin/ \
		http://www.us1.openh323.org/bin/ \
		http://www.us2.openh323.org/bin/ \
		http://www.ru.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.at.openh323.org/bin/ \
		http://www.cz.openh323.org/bin/ \
		http://www.pl.openh323.org/bin/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.openh323.org/

WRKSRC=		${WRKDIR}/openh323

MAKE_ENV+=	PWLIBDIR=${PREFIX} OPENH323DIR=${WRKSRC}

USE_GMAKE=	yes
USE_LIBTOOL=	yes

pre-build:
		-${MKDIR} ${WRKSRC}/lib; cd ${WRKSRC}/lib; ${LN} -s ${PREFIX}/lib/libpt.la

do-build:
		cd ${WRKSRC}; ${GMAKE} opt

post-install:
		cd ${WRKSRC}/include; for f in \*.h ; \
			do ${BSD_INSTALL_DATA} $$f ${PREFIX}/include; done
		-${MKDIR} ${PREFIX}/share/openh323
		cd ${WRKSRC}; ${BSD_INSTALL_DATA} openh323u.mak ${PREFIX}/share/openh323

.include "../../mk/bsd.pkg.mk"
