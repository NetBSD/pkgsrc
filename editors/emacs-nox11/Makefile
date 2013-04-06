# $NetBSD: Makefile,v 1.39 2013/04/06 11:23:04 rodent Exp $

DISTNAME=	emacs-nox11-${MY_EMACS_VERSION}
MYPKGREVISION=	0	# Do not remove this when zero

# XXX: must set this before including bsd.prefs.mk or it doesn't work.
META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

#
# Force a nox11 EMACS_TYPE. This way a bulk build will generate
# emacs meta-packages for use both with and without X.
#

.if empty(EMACS_TYPE:M*nox)
MY_EMACS_TYPE=	${EMACS_TYPE}nox
.endif

.include "../../editors/emacs/Makefile.common"
