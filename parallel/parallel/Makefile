# $NetBSD: Makefile,v 1.23 2022/06/28 11:35:24 wiz Exp $
#

DISTNAME=	parallel-20210722
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GNU:=parallel/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://savannah.gnu.org/projects/parallel/
COMMENT=	Build and execute shell commands in parallel
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	perl:run pod2man pod2html

REPLACE_PERL+=	src/parallel src/niceload src/sem src/sem.pod
REPLACE_PERL+=	src/sql src/parcat src/parsort
REPLACE_SH+=	src/env_parallel src/parset

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/parallel/LICENSES

CHECK_INTERPRETER_SKIP+=	bin/env_parallel.*

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/LICENSES/*.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/LICENSES

.include "../../mk/bsd.pkg.mk"
