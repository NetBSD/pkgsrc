# $NetBSD: Makefile,v 1.9 2020/11/05 09:07:52 ryoon Exp $
#

DISTNAME=		dia2code-0.8.1
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=dia2code/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://dia2code.sourceforge.net/
COMMENT=		Small utility used to generate code from a Dia diagram

GNU_CONFIGURE=		yes

SUBST_CLASSES+=		inc
SUBST_STAGE.inc=	post-configure
SUBST_FILES.inc=	Makefile */Makefile */*/Makefile */*/*/Makefile
SUBST_SED.inc=		-e 's:INCLUDES =:INCLUDES = -I${PREFIX}/include/libxml2/libxml :'

AUTO_MKDIRS=			yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dia2code/dia2code ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/dia2code.1
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/dia2code/README

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
