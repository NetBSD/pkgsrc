# $NetBSD: Makefile,v 1.31 2004/10/03 00:13:24 tv Exp $
#

.include "../../devel/GConf2/Makefile.common"

PKGNAME=	${DISTNAME:S/GConf/GConf2/}
PKGREVISION=	1

USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=	--disable-gtk

OWN_DIRS=	${PKG_SYSCONFDIR}/2
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.defaults
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.mandatory

EGDIR=		${PREFIX}/share/examples/GConf2
CONF_FILES=	${EGDIR}/path ${PKG_SYSCONFDIR}/2/path

PRINT_PLIST_AWK+=	/^@dirrm (include\/gconf|lib\/GConf|share\/gconf)$$/ \
				{ print "@unexec $${RMDIR} -p %D/" $$2 \
				        " 2>/dev/null || $${TRUE}"; next}

# XXX: We need to use XML_CATALOGS here to register the installed DTD.
#      But we have to wait until a public identifier is choosen for it.

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gconf/schemas

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
