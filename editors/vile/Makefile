# $NetBSD: Makefile,v 1.43 2005/09/27 22:49:27 agc Exp $

DISTNAME=		vile-9.5
CATEGORIES=		editors
MASTER_SITES=		ftp://dickey.his.com/vile/ \
			ftp://invisible-island.net/vile/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://dickey.his.com/vile/vile.html
COMMENT=		VI Like Emacs.  a vi "workalike", with many additional features

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-perl
CONFIGURE_ARGS+=	--datadir=${DATADIR}
CONFIGURE_ARGS+=	--with-libdir-path=${FILTERDIR}
USE_TOOLS+=		perl:run

CPPFLAGS.NetBSD+=	-DMISSING_EXTERN_ENVIRON

MAKEFILE=		makefile
INSTALL_TARGET=		install install-perl

DATADIR=		${PREFIX}/share/vile
FILTERDIR=		${PREFIX}/libexec/vile
EGDIR=			${PREFIX}/share/examples/vile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/perl/vileget ${PREFIX}/bin/vileget
	${INSTALL_DATA_DIR} ${EGDIR}
	for f in filters/spell.rc filters/filters.rc		\
		macros/digraphs.rc macros/pictmode.rc		\
		macros/manpage.rc visvile/visvile.rc; do	\
		${INSTALL_DATA} ${WRKSRC}/$$f ${EGDIR};		\
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
