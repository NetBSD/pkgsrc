# $NetBSD: Makefile,v 1.16 2003/12/12 22:33:36 jmmv Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/07/12 22:59:19 steve Exp $

DISTNAME=	pcre-4.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/	\
		ftp://pcre.sourceforge.net/pub/pcre/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	proff@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
