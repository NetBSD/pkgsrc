# $NetBSD: Makefile,v 1.9 2011/10/28 17:34:06 schnoebe Exp $

DISTNAME=		spectrum-1.4.8
CATEGORIES=		chat
MASTER_SITES=		http://spectrum.im/attachments/download/43/

MAINTAINER=		schnoebe@NetBSD.org
HOMEPAGE=		http://spectrum.im/
COMMENT=		XMPP transport/gateway based on libpurple
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-xmpppy>=0.4.1:../../chat/py-xmpppy
DEPENDS+=		${PYPKGPREFIX}-expat>=0nb4:../../textproc/py-expat

PYTHON_VERSIONS_ACCEPTED=	27 26 25

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config msgfmt xgettext
USE_CMAKE=		yes
USE_LANGUAGES=		c++ c

REPLACE_PYTHON+=	spectrumctl/spectrumctl.py
PY_PATCHPLIST=		yes

BUILD_DEFS+=		JABBER_USER JABBER_GROUP

.include "../../mk/bsd.prefs.mk"

JABBER_USER?=		jabberd
JABBER_GROUP?=		jabberd

FILES_SUBST+=		JABBER_USER=${JABBER_USER}
FILES_SUBST+=		JABBER_GROUP=${JABBER_GROUP}

PKG_GROUPS+=		${JABBER_GROUP}
PKG_USERS+=		${JABBER_USER}:${JABBER_GROUP}


PKG_SYSCONFSUBDIR=	spectrum
EGDIR=			${PREFIX}/share/examples/spectrum
# DOCDIR=			${PREFIX}/share/doc/spectrum
RCD_SCRIPTS=		spectrum

CONF_FILES+=		${EGDIR}/spectrum.cfg ${PKG_SYSCONFDIR}/spectrum.cfg

.include "options.mk"

SUBST_CLASSES+=		cfgpath
SUBST_STAGE.cfgpath=	post-patch
SUBST_FILES.cfgpath+=	src/configfile.cpp
SUBST_FILES.cfgpath+=	tools/migrate-db/main.cpp
SUBST_FILES.cfgpath+=	spectrumctl/spectrumctl.py
SUBST_FILES.cfgpath+=	man/spectrumctl.8
SUBST_MESSAGE.cfgpath=	Correcting configuration directory
SUBST_SED.cfgpath=	-e 's,/etc/spectrum,${PKG_SYSCONFDIR},g'
SUBST_SED.cfgpath+=	-e 's,@ETC_SPECTRUM@,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-patch
SUBST_FILES.manpath=	CMakeLists.txt
SUBST_MESSAGE.manpath=	Correcting man page directory
SUBST_SED.manpath+=	-e 's,@PKGMANDIR@,${PKGMANDIR},g'

SUBST_CLASSES+=		users
SUBST_STAGE.users=	post-patch
SUBST_FILES.users=	spectrumctl/spectrumctl.py
SUBST_FILES.users+=	spectrumctl/spectrum/env.py
SUBST_FILES.users+=	man/spectrumctl.8
SUBST_MESSAGE.users=	Correcting spectrum user
SUBST_SED.users=	-e 's/@SPECTRUM_USER@/${JABBER_USER}/g'

MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		JABBER_USER=${JABBER_USER}

INSTALLATION_DIRS=	bin ${PKG_SYSCONFDIR}
INSTALLATION_DIRS+=	share/locales
INSTALLATION_DIRS+=	${EGDIR}
# INSTALLATION_DIRS+=	${DOCDIR}

pre-install:
	${RM} -f ${WRKSRC}/spectrumctl/spectrumctl.py.orig
	${RM} -f ${WRKSRC}/spectrumctl/spectrum/env.py.orig
	${MKDIR} ${DESTDIR}${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/spectrum.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/schemas/mysql_schema.sql \
					${DESTDIR}${EGDIR}/spectrum-mysql.sql


.include "../../chat/libpurple/buildlink3.mk"
.include "../../chat/gloox/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
# .include "../../devel/libev/buildlink3.mk"
.include "../../devel/poco/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
