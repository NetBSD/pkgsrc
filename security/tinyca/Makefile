# $NetBSD: Makefile,v 1.4 2005/06/17 03:50:33 jlam Exp $

DISTNAME=	tinyca-0.6.8
CATEGORIES=	security
MASTER_SITES=	http://tinyca.sm-zone.net/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://tinyca.sm-zone.net/
COMMENT=	GUI written in Perl/Gtk to manage a small CA

DEPENDS+=	p5-gtk>=0.7009:../../x11/p5-gtk
DEPENDS+=	p5-Gdk-Imlib>=0.7009:../../graphics/p5-Gdk-Imlib
DEPENDS+=	p5-Gnome>=0.7009:../../graphics/p5-Gnome
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=	zip-[0-9]*:../../archivers/zip

NO_BUILD=	YES
USE_PERL5=	YES
CADIR=		${PREFIX}/share/tinyca

REPLACE_PERL=	tinyca
BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.7d

SUBST_CLASSES+=		script
SUBST_STAGE.script=	post-patch
SUBST_FILES.script=	tinyca
SUBST_SED.script=	-e "s|./lib|${CADIR}|g" \
			-e "s|/usr/bin/openssl\
			|${BUILDLINK_PREFIX.openssl}/bin/openssl|g" \
			-e "s|/usr/bin/zip|${PREFIX}/bin/zip|g" \
			-e "s|./templates|${CADIR}/templates|g"
SUBST_MESSAGE.script=	"Fixing hardcoded paths."

INSTALLATION_DIRS=	bin

.include "../../security/openssl/buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${CADIR}
	${INSTALL_DATA_DIR} ${CADIR}/GUI
	${INSTALL_DATA_DIR} ${CADIR}/templates
	${INSTALL_SCRIPT} ${WRKSRC}/tinyca ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/*.pm ${CADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/GUI/*.pm ${CADIR}/GUI
	${INSTALL_DATA} ${WRKSRC}/templates/openssl.cnf ${CADIR}/templates

.include "../../mk/bsd.pkg.mk"
