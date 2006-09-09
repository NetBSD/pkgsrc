# $NetBSD: Makefile,v 1.4 2006/09/09 02:46:08 obache Exp $
DISTNAME=	BibTool-2.48
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/bibtool/}

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.gerd-neugebauer.de/software/TeX/BibTool.en.html
COMMENT=	Tool to manipulate BibTeX databases

GNU_CONFIGURE=		yes
MAKE_FILE=	makefile
#CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/BibTcl

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	/usr/local/bin/tclsh
REPLACE.tcl.new=	/usr/pkg/bin/tclsh
REPLACE_FILES.tcl=	Tcl/bibtool.tcl
REPLACE_PERL+=		Perl/bibtool.pl

DOCDIR=		${LOCALBASE}/share/doc/BibTool
EXAMPLEDIR=	${LOCALBASE}/share/examples/BibTool

TEX_ACCEPTED=   teTeX3
TEX_DEPMETHOD=  build
.include "../../mk/tex.buildlink3.mk"

#pre-configure:
#	rm ${WRKSRC:Q}/BibTcl/Makefile
#	mv ${WRKSRC:Q}/BibTcl/Makefile.in ${WRKSRC:Q}/BibTcl/makefile.in

post-build:
	cd ${WRKSRC:Q}/Doc && make
#	cd ${WRKSRC:Q}/BibTcl && make

post-install:
	cd ${WRKSRC:Q} && make install.man
	${MKDIR} ${DOCDIR}
	for i in ${WRKSRC:Q}/Doc/*.dvi; do ${INSTALL_DATA} $$i ${DOCDIR}; done
	${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/Perl/bibtool.pl ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC:Q}/Tcl/bibtool.tcl ${EXAMPLEDIR}
#	cd ${WRKSRC:Q}/BibTcl && make install

.include "../../mk/bsd.pkg.mk"
