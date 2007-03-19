# $NetBSD: Makefile,v 1.1.1.1 2007/03/19 12:47:47 rillig Exp $
#

DISTNAME=		dia2code-0.8.1
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

INSTALLATION_DIRS_FROM_PLIST=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dia2code/dia2code ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${PREFIX}/${PKGMANDIR}/man1/dia2code.1
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dia2code/README

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
