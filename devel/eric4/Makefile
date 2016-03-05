# $NetBSD: Makefile,v 1.46 2016/03/05 11:28:21 jperkin Exp $

VERS=			4.5.24
DISTNAME=		eric4-${VERS}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eric-ide/}

MAINTAINER=		helgoman@users.sourceforge.net
HOMEPAGE=		http://eric-ide.python-projects.org/index.html
COMMENT=		Python - IDE
LICENSE=		gnu-gpl-v3

NO_BUILD=		yes
EXTRACT_USING=		bsdtar

PY_PATCHPLIST=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 4.5.18

CONFIGURE_ARGS+=		-b ${PREFIX}/bin
CONFIGURE_ARGS+=		-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=		-a ${PREFIX}/qt4/qsci/api
CONFIGURE_ARGS+=		-i ${DESTDIR}

REPLACE_PYTHON+=	eric/Examples/hallo.py
REPLACE_PYTHON+=	eric/Examples/rhallo.py
REPLACE_PYTHON+=	eric/compileUiFiles.py
REPLACE_PYTHON+=	eric/eric4.py
REPLACE_PYTHON+=	eric/eric4_api.py
REPLACE_PYTHON+=	eric/eric4_compare.py
REPLACE_PYTHON+=	eric/eric4_configure.py
REPLACE_PYTHON+=	eric/eric4_diff.py
REPLACE_PYTHON+=	eric/eric4_doc.py
REPLACE_PYTHON+=	eric/eric4_editor.py
REPLACE_PYTHON+=	eric/eric4_iconeditor.py
REPLACE_PYTHON+=	eric/eric4_plugininstall.py
REPLACE_PYTHON+=	eric/eric4_pluginrepository.py
REPLACE_PYTHON+=	eric/eric4_pluginuninstall.py
REPLACE_PYTHON+=	eric/eric4_qregexp.py
REPLACE_PYTHON+=	eric/eric4_re.py
REPLACE_PYTHON+=	eric/eric4_sqlbrowser.py
REPLACE_PYTHON+=	eric/eric4_tray.py
REPLACE_PYTHON+=	eric/eric4_trpreviewer.py
REPLACE_PYTHON+=	eric/eric4_uipreviewer.py
REPLACE_PYTHON+=	eric/eric4_unittest.py
REPLACE_PYTHON+=	eric/eric4_webbrowser.py
REPLACE_PYTHON+=	eric/install-i18n.py
REPLACE_PYTHON+=	eric/install.py
REPLACE_PYTHON+=	eric/uninstall.py
REPLACE_PYTHON+=	install.py
REPLACE_PYTHON+=	uninstall.py

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} install.py ${CONFIGURE_ARGS})

.include "options.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/py-qt4-qscintilla/buildlink3.mk"
BUILDLINK_API_DEPENDS.pyxml+=	${PYPKGPREFIX}-xml>=0.8.4nb3
.include "../../mk/bsd.pkg.mk"
