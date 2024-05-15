# $NetBSD: Makefile,v 1.3 2024/05/15 13:30:50 wiz Exp $

DISTNAME=	emacspeak-60.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tvraman/}
GITHUB_PROJECT=	emacspeak
# The .tar.bz2 of release 60.0 is broken and upstream won't fix
# it.  Switch to the auto-generated repository snapshot for the 60.0
# release instead. This file is much bigger than the .tar.bz2 (100
# MB vs. 5 MB) so we should switch back to .tar.bz2 on the next
# release.
#EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://emacspeak.sourceforge.net/
COMMENT=	Speech interface for emacs
LICENSE=	gnu-gpl-v2

DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv
DEPENDS+=	sox-[0-9]*:../../audio/sox

USE_TOOLS=	gmake perl bash:run pax

REPLACE_PERL=	etc/*
REPLACE_BASH=	bash-utils/* etc/* sounds/*/*sh

EMACS_VERSIONS_ACCEPTED=	emacs29 emacs29nox

# More than shebang, cant' use REPLACE_INTERPRETER
SUBST_CLASSES+=			fix-tclsh
SUBST_STAGE.fix-tclsh=		pre-configure
SUBST_MESSAGE.fix-tclsh=	Fixing tclsh path
SUBST_FILES.fix-tclsh=		servers/*
SUBST_SED.fix-tclsh=		-e 's,/usr/bin/tclsh,${PREFIX}/bin/tclsh,'

REPLACE_PYTHON+=		etc/*streamtheworld.py
REPLACE_PYTHON+=		servers/mac

# Fix sox path
SUBST_CLASSES+=			fix-sox-path
SUBST_STAGE.fix-sox-path=	pre-configure
SUBST_MESSAGE.fix-sox-path=	Fixing sox path
SUBST_FILES.fix-sox-path=	servers/tts-lib.tcl
SUBST_SED.fix-sox-path=		-E -e 's,/usr/bin/(sox|play),${PREFIX}/bin/\1,'

# Use sox as default player
SUBST_CLASSES+=			sox-player
SUBST_STAGE.sox-player=		pre-configure
SUBST_MESSAGE.sox-player=	Use sox as default player
SUBST_FILES.sox-player=		servers/tts-lib.tcl
SUBST_SED.sox-player=		-E -e 's,/usr/bin/paplay,${PREFIX}/bin/play,'

# Change BATCH variable's name
SUBST_CLASSES+=			es_batch
SUBST_STAGE.es_batch=		pre-configure
SUBST_MESSAGE.es_batch=		Change BATCH variable's name
SUBST_FILES.es_batch=		lisp/Makefile
SUBST_SED.es_batch=		-E -e 's/BATCH/ES_BATCH/'

USE_LANGUAGES+=	c c++

BUILD_TARGET=	all espeak

post-build:
	cd ${WRKSRC} && \
	for i in bash-utils/remote \
			etc/COPYRIGHT \
			etc/Makefile \
			etc/forms/apache-clf.el \
			etc/forms/messages.el \
			etc/remote.txt \
			xsl/README; do \
		${CHMOD} 644 "$$i"; \
	done; \
	for i in 	servers/native-espeak/Makefile.orig \
			lisp/emacspeak-bookshare.el.orig \
			.excludes.orig; do \
		rm "$$i"; \
	done; \
	for i in $$(cat .excludes); do \
		rm -rf "$$i"; \
	done
# This last for-done and ".excludes.orig; do \" above should be
# removed in the next release...

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/emacspeak

do-install:
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${EMACS_LISPPREFIX}/emacspeak

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tclx/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../audio/espeak-ng/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
