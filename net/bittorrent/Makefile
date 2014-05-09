# $NetBSD: Makefile,v 1.47 2014/05/09 07:37:13 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/BitT/bitt/}
PKGREVISION=	6

CONFLICTS+=	bittornado-[0-9]*
CONFLICTS+=	BitTornado-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel

USE_TOOLS+=	msgfmt xgettext msgmerge

SUBST_CLASSES+=         sha
SUBST_MESSAGE.sha=	Fixing references to deprecated sha module.
SUBST_STAGE.sha=	pre-configure
SUBST_FILES.sha=	BitTorrent/ConvertedMetainfo.py
SUBST_FILES.sha+=	BitTorrent/NewVersion.py
SUBST_FILES.sha+=	BitTorrent/PeerID.py
SUBST_FILES.sha+=	BitTorrent/StorageWrapper.py
SUBST_FILES.sha+=	BitTorrent/download.py
SUBST_FILES.sha+=	BitTorrent/makemetafile.py
SUBST_FILES.sha+=	BitTorrent/parsedir.py
SUBST_FILES.sha+=	khashmir/khash.py
SUBST_FILES.sha+=	khashmir/khashmir.py
SUBST_FILES.sha+=	khashmir/utkhashmir.py
SUBST_FILES.sha+=	torrentinfo-console.py
SUBST_SED.sha=		-e "s/^from sha import .*/from hashlib import sha1 as sha/"

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 4.4.0

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
