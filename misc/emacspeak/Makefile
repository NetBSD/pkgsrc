# $NetBSD: Makefile,v 1.1 2024/03/13 05:48:35 wiz Exp $

DISTNAME=	emacspeak-59.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tvraman/}
GITHUB_PROJECT=	emacspeak
GITHUB_RELEASE=	59
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://emacspeak.sourceforge.net/
COMMENT=	Speech interface for emacs
LICENSE=	gnu-gpl-v2

USE_TOOLS=	gmake perl bash pax

REPLACE_PERL=	etc/*
REPLACE_BASH=	bash-utils/* etc/*

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
SUBST_FILES.fix-sox-path+=	lisp/emacspeak-sounds.el
SUBST_SED.fix-sox-path=		-E -e 's,/usr/bin/(sox|play),${PREFIX}/bin/\1,'

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
			media/welcome.ra \
			xsl/README; do \
		${CHMOD} 644 "$$i"; \
	done; \
	for i in 	servers/native-espeak/Makefile.orig \
			lisp/emacspeak-bookshare.el.orig \
			servers/tts-lib.tcl.orig; do \
		rm "$$i"; \
	done

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/emacspeak

do-install:
	cd ${WRKSRC} && pax -rw * ${DESTDIR}${EMACS_LISPPREFIX}/emacspeak

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tclx/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../audio/espeak-ng/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../editors/emacs/modules.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
