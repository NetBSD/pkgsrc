# $NetBSD: Makefile,v 1.8 1999/12/03 16:23:17 rh Exp $
# FreeBSD: ports/misc/fd/Makefile,v 1.14 1999/08/25 07:21:37 obrien Exp
#

DISTNAME=	FD-1.03l
PKGNAME=	fd-1.03l
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/FDclone/

MAINTAINER=	nobu@psrc.isac.co.jp

MANLANG=	ja
MAN1=		fd.1
MAKE_ENV=	LANG=${MANLANG}
DOCS=		README FAQ HISTORY ToAdmin
SIGNATURE=	Nobuhiro Yasutomi <${MAINTAINER}>

# require maintainer signature for binary package distributions
do-configure:
	@cd ${WRKSRC}; v=version.h; ${MV} $$v $$v.orig; \
	${SED} 's/\(distributor = \)NULL/\1"${SIGNATURE}"/' $$v.orig > $$v

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fd
	@for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/fd; \
	done
.endif
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
