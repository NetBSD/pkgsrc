# $NetBSD: Makefile,v 1.5 2017/08/01 17:40:10 wiz Exp $
#

DISTNAME=	gflib
PKGNAME=	gflib-20030604
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.utk.edu/~plank/plank/gflib/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cs.utk.edu/~plank/plank/gdlib/
COMMENT=	Reed Solomon and Galois Field error correction library

MAKE_FILE=	makefile

BUILD_TARGET=	w16

INSTALLATION_DIRS=	bin

do-install:
	for f in gf_div gf_mult parity_test rs_decode_file		\
			rs_encode_file xor; do				\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f			\
			${DESTDIR}${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
