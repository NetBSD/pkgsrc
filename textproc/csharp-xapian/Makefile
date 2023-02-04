# $NetBSD: Makefile,v 1.28 2023/02/04 14:28:19 schmonz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
COMMENT=		C\# bindings for Xapian search engine
HOMEPAGE=		https://xapian.org/docs/bindings/csharp/

CONFIGURE_ARGS+=	--with-csharp

GENERATE_PLIST+=	\
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};
PLIST_SRC=		# none

.include "../../lang/mono/buildlink3.mk"
.include "../../textproc/xapian/module.mk"
.include "../../mk/bsd.pkg.mk"
