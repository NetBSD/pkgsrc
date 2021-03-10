# $NetBSD: Makefile,v 1.14 2021/03/10 16:35:53 jperkin Exp $
#
# Note to packagers:
# packages installing additional completion files should drop
# them into ${DESTDIR}${PREFIX}/share/bash-completion/completions
# with the name of the package as file name.

DISTNAME=	bash-completion-2.11
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=scop/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scop/bash-completion
COMMENT=	Programmable completion specifications for bash
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gmake

USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	lib/pkgconfig

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/pkgconfig/bash-completion.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/bash-completion.pc

.include "../../mk/bsd.pkg.mk"
