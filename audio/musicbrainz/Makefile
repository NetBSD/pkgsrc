# $NetBSD: Makefile,v 1.5 2003/07/21 16:30:42 martti Exp $

DISTNAME=	libmusicbrainz-2.0.0
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	Second generation incarnation of the CD Index

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
