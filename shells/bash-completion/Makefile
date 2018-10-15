# $NetBSD: Makefile,v 1.9 2017/03/14 14:51:28 jperkin Exp $
#
# Note to packagers:
# packages installing additional completion files should drop
# them into ${DESTDIR}${PREFIX}/share/bash-completion.d
# with the name of the package as file name.

VERSION=	2.8
DISTNAME=	bash-completion-${VERSION}
CATEGORIES=	shells
MASTER_SITES=	-https://github.com/scop/bash-completion/archive/${VERSION}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bash-completion.alioth.debian.org/
COMMENT=	Programmable completion specifications for bash
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gmake autoconf automake

USE_LANGUAGES=	# none
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,/etc/bash_completion.d,${PREFIX}/share/bash-completion.d,g"
SUBST_SED.path+=	-e "s,/etc/bash_completion,${PREFIX}/share/bash-completion/bash_completion,g"
SUBST_STAGE.path=	pre-build
SUBST_FILES.path+=	README
SUBST_MESSAGE.path=	Fixing path to completion files.

pre-configure:
	set -e; cd ${WRKSRC}; \
	autoreconf -i

# aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../mk/bsd.pkg.mk"
