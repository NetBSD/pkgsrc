# $NetBSD: Makefile,v 1.1.1.1 2004/10/19 16:16:00 adrianp Exp $
#

DISTNAME=		InlineEgg-1.07
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oss.corest.com/projects/inlineegg.html
COMMENT=		Python module for writing inline assembler programs

LICENSE=		inlineegg-license

USE_BUILDLINK3=		YES
PY_PATCHPLIST=		YES
PYDISTUTILSPKG=		YES

PYTHON_VERSIONS_ACCEPTED=	23 22 21 23pth 22pth 21pth
PYTHON_PATCH_SCRIPTS=		examples/example1.py examples/example2.py \
				examples/example3.py examples/example4.py \
				examples/example5.py examples/example6.py \
				xored_shell_client.py

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/InlineEgg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/InlineEgg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/InlineEgg
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.py \
		${PREFIX}/share/examples/InlineEgg

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
