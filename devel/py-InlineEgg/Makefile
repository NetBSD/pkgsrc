# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:28 joerg Exp $
#

DISTNAME=		InlineEgg-1.08
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oss.corest.com/projects/inlineegg.html
COMMENT=		Python module for writing inline assembler programs

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		inlineegg-license

PY_PATCHPLIST=		YES
PYDISTUTILSPKG=		YES

PYTHON_VERSIONS_ACCEPTED=	25 24 23 21
PYTHON_PATCH_SCRIPTS=		examples/example1.py examples/example2.py \
				examples/example3.py examples/example4.py \
				examples/example5.py examples/example6.py \
				xored_shell_client.py

INSTALLATION_DIRS=	share/doc/InlineEgg share/examples/InlineEgg

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/InlineEgg
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.py \
		${DESTDIR}${PREFIX}/share/examples/InlineEgg

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
