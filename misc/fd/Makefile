# $NetBSD: Makefile,v 1.15 2001/06/26 11:40:43 wiz Exp $
#

DISTNAME=	FD-1.03s
PKGNAME=	fd-1.03s
CATEGORIES=	misc
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/

MAINTAINER=	Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
COMMENT=	File and directory management tool

MANLANG=	ja
MAKE_ENV=	LANG=${MANLANG}
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
