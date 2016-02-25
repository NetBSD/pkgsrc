# $NetBSD: Makefile,v 1.30 2016/02/25 13:19:47 jperkin Exp $
#

.include		"../../games/nethack-lib/Makefile.common"

PKGNAME=		nethack-lib-${NETHACK_VERSION}
PKGREVISION=		4

COMMENT=		Data files for Nethack

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh
BUILD_TARGET=		datastuff
INSTALL_TARGET=		manpages install-dat
INSTALLATION_DIRS=	${PKGMANDIR}/man6

# Using 'nroff -Tascii' works better with groff and we don't want to use col
# on linux as it removes the escape the the ansi color sequences.
SUBST_CLASSES.Linux+=	nroff
SUBST_STAGE.nroff=	pre-configure
SUBST_MESSAGE.nroff=	Fixing Guidebook format command.
SUBST_FILES.nroff=	sys/unix/Makefile.doc
SUBST_SED.nroff=	-e '/^GUIDECMD/s,nroff .*$$,nroff -Tascii,'

# Special handling for the scorefiles: we do not want to delete
# them between package installations and deinstallations.
#
# These should eventually migrate to a better location, but keep them
# here for now until we lose backward compatibility because of changes
# to the fileformat.
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/logfile \
			${NETHACK_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/perm \
			${NETHACK_USER} ${NETHACK_GROUP} 664
CONF_FILES_PERMS+=	/dev/null ${VARDIR}/record \
			${NETHACK_USER} ${NETHACK_GROUP} 664

REQD_DIRS_PERMS+=	${VARDIR}					\
			${NETHACK_USER} ${NETHACK_GROUP} 775
REQD_DIRS_PERMS+=	${VARDIR}/save					\
			${NETHACK_USER} ${NETHACK_GROUP} 770

CHECK_FILES_SKIP+=	${VARDIR}/logfile				\
			${VARDIR}/perm					\
			${VARDIR}/record

.include "../../mk/bsd.pkg.mk"
