# $NetBSD: Makefile,v 1.26 2023/06/06 12:42:11 riastradh Exp $

DISTNAME=	BibTool-2.65
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/bibtool/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerd-neugebauer.de/software/TeX/BibTool.en.html
COMMENT=	Tool to manipulate BibTeX databases
LICENSE=	gnu-gpl-v1

TOOL_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TOOL_DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
TOOL_DEPENDS+=	tex-bookmark-[0-9]*:../../print/tex-bookmark
TOOL_DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
TOOL_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
TOOL_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TOOL_DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
TOOL_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TOOL_DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
TOOL_DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
TOOL_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
TOOL_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk

GNU_CONFIGURE=		yes
MAKE_FILE=		makefile
#CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/BibTcl
WRKSRC=			${WRKDIR}/${PKGBASE}
USE_TOOLS+=		perl

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	/usr/local/bin/tclsh
REPLACE.tcl.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tcl=	Tcl/bibtool.tcl
REPLACE_PERL+=		Perl/bibtool.pl

DOCDIR=			${PREFIX}/share/doc/BibTool
EXAMPLEDIR=		${PREFIX}/share/examples/BibTool

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_TARGET=		install install.man
INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLEDIR}

#pre-configure:
#	rm ${WRKSRC}/BibTcl/Makefile
#	mv ${WRKSRC}/BibTcl/Makefile.in ${WRKSRC}/BibTcl/makefile.in

post-build:
	cd ${WRKSRC}/doc && ${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE}

post-install:
	set -e; for i in ${WRKSRC}/doc/*.pdf; do \
		${INSTALL_DATA} "$$i" ${DESTDIR}${DOCDIR}; \
	 done
	${INSTALL_DATA} ${WRKSRC}/Perl/bibtool.pl ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Tcl/bibtool.tcl ${DESTDIR}${EXAMPLEDIR}
#	cd ${WRKSRC}/BibTcl && make install

.include "../../mk/bsd.pkg.mk"
