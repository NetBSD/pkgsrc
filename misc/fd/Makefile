# $NetBSD: Makefile,v 1.19 2005/12/05 20:50:39 rillig Exp $
#

DISTNAME=	FD-1.03u
PKGNAME=	fd-1.03u
CATEGORIES=	misc
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/

MAINTAINER=	nobu@psrc.isac.co.jp
COMMENT=	File and directory management tool

MANLANG=	ja
MAKE_ENV+=	LANG=${MANLANG:Q}
DOCS=		README FAQ HISTORY ToAdmin

# require maintainer signature for binary package distributions
do-configure:
	@cd ${WRKSRC}; v=version.h; ${MV} $$v $$v.orig; \
	${SED} 's/\(distributor = \)NULL/\1"${MAINTAINER}"/' $$v.orig > $$v

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fd
	@for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/fd; \
	done

.include "../../mk/bsd.pkg.mk"
