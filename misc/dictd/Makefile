# $NetBSD: Makefile,v 1.1.1.1 2002/10/04 09:05:26 uebayasi Exp $

DISTNAME=       dictd-1.8.0
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.dict.org/pub/dict/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary server

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined
USE_GMAKE=	# defined

CPPFLAGS+=	-I${BUILDLINK_DIR}/include

# T_USER is defined in machine/trap.h and ${ARCH}/trap.h.
post-patch:
	${GREP} -lr T_USER ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} \
		    -e 's|T_USER|T_XUSER|g' \
		    -e 's|DICT_XUSER|DICT_USER|g' \
		$${f}.orig >$$f; \
	done

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
