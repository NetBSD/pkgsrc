# $NetBSD: Makefile,v 1.5 2006/12/28 11:47:51 wiz Exp $

DISTNAME=	festdoc-1.4.0.1
PKGNAME=	festival-doc-1.4.0.1
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/ \
		http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cstr.ed.ac.uk/projects/festival/
COMMENT=	Festival documentation, in (tex)info, html, dvi and ps formats

NO_BUILD=	yes

DOC=		${PREFIX}/share/doc/festival

INFO_FILES=	# PLIST

INSTALLATION_DIRS=	${PKGINFODIR}

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${RM} ${WRKSRC}/festival/src-manual/c3750.htm~
	${RM} ${WRKSRC}/speechtools/c16909.htm~
	${RMDIR} ${WRKSRC}/festival/src-manual/images_gen

do-install:
	${INSTALL_DATA_DIR} ${DOC}
	cd ${WRKSRC};							\
	${PAX} -rw speechtools ${DOC};					\
	cd festival;							\
	for f in info/*.info info/*.info-[0-9]*; do			\
		${INSTALL_DATA} $${f} ${PREFIX}/${PKGINFODIR};		\
	done;								\
	${PAX} -rw user-manual ${DOC};					\
	${PAX} -rw src-manual ${DOC};					\
	for f in festival.* refcard.*; do				\
		${INSTALL_DATA} $${f} ${DOC};				\
	done

.include "../../mk/bsd.pkg.mk"
