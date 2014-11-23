# $NetBSD: Makefile,v 1.23 2014/11/23 05:59:45 mef Exp $

DISTNAME=	gnus-5.10.10
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail news
MASTER_SITES=	http://gnus.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnus.org/
COMMENT=	Gnus is a flexible message reader running under GNU Emacs
LICENSE=	gnu-gpl-v3

#EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20 xemacs211 xemacs215

DEPENDS+=	digest>=20010101:../../pkgtools/digest

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-lispdir=${EMACS_LISPPREFIX}/gnus
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/share/gnus
CONFIGURE_ENV+=		EMACS=${EMACS_BIN:Q}
EMACS_MODULES+=		base

# Avoid conflicting with Emacsen provided gnus info files
GNU_CONFIGURE_INFODIR=	${PREFIX}/share/doc/gnus/info

USE_TOOLS+=		makeinfo
INFO_FILES=		yes

SUBST_CLASSES+=		destdir
SUBST_FILES.destdir=	etc/Makefile.in lisp/Makefile.in texi/Makefile.in
SUBST_STAGE.destdir=	post-patch
SUBST_MESSAGE.destdir=	Convert install to ${DESTDIR}
SUBST_SED.destdir=	-e  '/(etcdir)/s,\$$(etcdir),\$$(DESTDIR)/\$$(etcdir)/,'
SUBST_SED.destdir+=	-e '/(lispdir)/s,\$$(lispdir),\$$(DESTDIR)/\$$(lispdir)/,'
SUBST_SED.destdir+=	-e '/(infodir)/s,\$$(infodir),\$$(DESTDIR)/\$$(infodir)/,'

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
