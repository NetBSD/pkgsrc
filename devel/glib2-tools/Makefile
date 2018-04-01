# $NetBSD: Makefile,v 1.4 2018/04/01 20:26:25 joerg Exp $

.include "../../devel/glib2/Makefile.common"

PKGNAME:=	${PKGNAME:S/glib2/glib2-tools/}
PKGREVISION=	1
CATEGORIES=	devel gnome

COMMENT=	GLib2/gobject python-dependent tools

NO_BUILD=		yes

PYSCRIPTS=		glib-genmarshal glib-mkenums
INSTALLATION_DIRS=	bin

do-configure:
.for f in ${PYSCRIPTS}
	cd ${WRKSRC}/gobject \
	&& ${SED} \
		-e "s,@PYTHON@,${PYTHONBIN}," \
		-e "s,@VERSION@,${PKGVERSION}," \
		${f}.in > ${f}
.endfor

do-install:
	cd ${WRKSRC}/gobject \
	&& ${INSTALL_SCRIPT} ${PYSCRIPTS} ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
