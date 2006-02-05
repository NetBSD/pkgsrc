# $NetBSD: Makefile,v 1.17 2006/02/05 23:10:31 joerg Exp $

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
PKGREVISION=	4
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tf.tcp.com/~hawkeye/tf/
COMMENT=	Popular programmable MUD client, with macro support and more


MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV+=	TFVER=${DISTNAME:S/^tf-//:Q}

PATCH_SITES=	http://discworld.imaginary.com/external/taffyd/
PATCHFILES=	tf-40s1-mccp-patch.gz
PATCH_DIST_STRIP=-p1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
