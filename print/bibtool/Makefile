# $NetBSD: Makefile,v 1.10 2012/12/24 00:54:05 dholland Exp $
DISTNAME=	BibTool-2.48
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/bibtool/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerd-neugebauer.de/software/TeX/BibTool.en.html
COMMENT=	Tool to manipulate BibTeX databases
#LICENSE=	gnu-gpl-v1

BUILD_DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
BUILD_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
BUILD_DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
BUILD_DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk

GNU_CONFIGURE=		yes
MAKE_FILE=	makefile
#CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/BibTcl

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	/usr/local/bin/tclsh
REPLACE.tcl.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tcl=	Tcl/bibtool.tcl
REPLACE_PERL+=		Perl/bibtool.pl

DOCDIR=		${LOCALBASE}/share/doc/BibTool
EXAMPLEDIR=	${LOCALBASE}/share/examples/BibTool

INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
INSTALL_TARGET=	install install.man
INSTALLATION_DIRS=	${DOCDIR} ${EXAMPLEDIR}

#pre-configure:
#	rm ${WRKSRC:Q}/BibTcl/Makefile
#	mv ${WRKSRC:Q}/BibTcl/Makefile.in ${WRKSRC:Q}/BibTcl/makefile.in

post-build:
	cd ${WRKSRC:Q}/Doc && make
#	cd ${WRKSRC:Q}/BibTcl && make

post-install:
	for i in ${WRKSRC:Q}/Doc/*.dvi; do ${INSTALL_DATA} $$i ${DESTDIR}${DOCDIR}; done
	${INSTALL_DATA} ${WRKSRC:Q}/Perl/bibtool.pl ${DESTDIR}${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/Tcl/bibtool.tcl ${DESTDIR}${EXAMPLEDIR}
#	cd ${WRKSRC:Q}/BibTcl && make install

.include "../../mk/bsd.pkg.mk"
