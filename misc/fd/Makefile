# $NetBSD: Makefile,v 1.10 2000/10/19 04:26:39 hubertf Exp $
# FreeBSD: ports/misc/fd/Makefile,v 1.14 1999/08/25 07:21:37 obrien Exp
#

DISTNAME=	FD-1.03o
PKGNAME=	fd-1.03o
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/FDclone/ \
		http://hp.vector.co.jp/authors/VA012337/soft/fd/

MAINTAINER=	Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>

MANLANG=	ja
MAN1=		fd.1
MAKE_ENV=	LANG=${MANLANG}
DOCS=		README FAQ HISTORY ToAdmin

# require maintainer signature for binary package distributions
do-configure:
	@cd ${WRKSRC}; v=version.h; ${MV} $$v $$v.orig; \
	${SED} 's/\(distributor = \)NULL/\1"${MAINTAINER}"/' $$v.orig > $$v

post-install:
	@${MKDIR} ${PREFIX}/share/doc/fd
	@for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/fd; \
	done
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
