# $NetBSD: Makefile,v 1.3 2003/02/20 16:02:34 salo Exp $

DISTNAME=	libmusicbrainz-2.0.0
PKGNAME=	${DISTNAME:S/lib//}
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.musicbrainz.org/
COMMENT=	second generation incarnation of the CD Index

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
