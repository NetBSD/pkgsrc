# $NetBSD: Makefile,v 1.12 2003/07/17 21:33:02 grant Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/07/12 22:59:19 steve Exp $

DISTNAME=	pcre-3.9
PKGREVISION=	1
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

.include "../../mk/bsd.pkg.mk"
