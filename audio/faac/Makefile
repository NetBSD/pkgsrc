# $NetBSD: Makefile,v 1.7 2006/03/04 21:28:54 jlam Exp $
#

DISTNAME=	faac-1.24
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=faac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.audiocoding.com/
COMMENT=	AAC audio encoder

USE_LIBTOOL=	yes
USE_TOOLS+=	automake
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/faac

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

pre-configure:
	cd ${WRKSRC};						\
	${LIBTOOLIZE} --automake;				\
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
