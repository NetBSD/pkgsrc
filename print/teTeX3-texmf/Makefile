# $NetBSD: Makefile,v 1.21 2009/01/11 09:05:27 minskim Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
PKGREVISION=	7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org,pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

PKG_DESTDIR_SUPPORT=	user-destdir
NOT_FOR_BULK_PLATFORM=	HPUX-*-*

CONFLICTS+=	teTeX-share-[0-9]*

WRKSRC=		${WRKDIR}/tetex
EXTRACT_DIR=	${WRKSRC}
NO_BUILD=	yes

REPLACE_PERL+=	doc/generic/ruhyphen/reduce-patt doc/generic/ruhyphen/sorthyph
# No dependency on Perl.
CHECK_INTERPRETER_SKIP+=share/texmf-dist/doc/generic/ruhyphen/reduce-patt \
			share/texmf-dist/doc/generic/ruhyphen/sorthyph
REPLACE_SH+=	doc/latex/bibunits/bibtexall doc/latex/multibib/bibtexall
USE_TOOLS+=	sh:run pax

.include "../../print/kpathsea/texmf.mk"

post-extract:
	rm -f ${WRKSRC}/ls-R
	rmdir ${WRKSRC}/doc/generic/pdfcrop
	rmdir ${WRKSRC}/fonts/cmap
	rmdir ${WRKSRC}/fonts/lig
	rmdir ${WRKSRC}/fonts/map/dvipdfm/updmap
	rmdir ${WRKSRC}/fonts/map/dvips/updmap
	rmdir ${WRKSRC}/fonts/map/pdftex/updmap
	rmdir ${WRKSRC}/fonts/misc
	rmdir ${WRKSRC}/fonts/opentype
	rmdir ${WRKSRC}/fonts/pk
	rmdir ${WRKSRC}/fonts/sfd
	rmdir ${WRKSRC}/fonts/truetype
	rmdir ${WRKSRC}/fonts/type3
	rmdir ${WRKSRC}/fonts/type42

do-install:
	cd ${WRKSRC} && pax -wr -s ',.*\.orig$$,,' * ${DESTDIR}${PREFIX}/share/texmf-dist

.include "../../mk/bsd.pkg.mk"
