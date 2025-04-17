# $NetBSD: Makefile,v 1.38 2025/04/17 21:52:33 wiz Exp $

PKGNAME=		csharp-${PKGNAME_MODULE}
PKGREVISION=		1
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
