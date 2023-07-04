# $NetBSD: Makefile,v 1.1 2023/07/04 16:08:17 nia Exp $

DISTNAME=	bulk-test-essential-20230704
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nia@NetBSD.org
COMMENT=	Meta-package for testing essential packages

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

#
# Start out with some popular languages and database engines where
# we ship multiple versions/implementations.
#
# pkgsrc's default versions should be reasonable for the given platform.
# If one fails, it should be switched.
#
# Keep in sync with:
# https://wiki.netbsd.org/languages/
#

.include "../../mk/bsd.prefs.mk"

.include "../../lang/lua/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.if ${MACHINE_ARCH} != "vax" # FP issues
.  include "../../lang/python/pyversion.mk"
.endif
.include "../../lang/ruby/buildlink3.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"

.if ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "aarch64" || \
    ${MACHINE_ARCH} == "earmv7hf"
.  include "../../lang/go/version.mk"
DEPENDS+=	${GO_PACKAGE_DEP}
.endif

.if ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "aarch64" || \
    ${MACHINE_ARCH} == "earmv7hf"
.  include "../../mk/java-vm.mk"
.endif

#
# Big desktop environment meta-packages.
# These ones are both popular among NetBSD users and reasonably
# portable. If they go missing, it also affects downstream
# distributors.
#
.if ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "aarch64"
DEPENDS+=	mate-[0-9]*:../../meta-pkgs/mate
DEPENDS+=	xfce4-[0-9]*:../../meta-pkgs/xfce4
.endif

#
# In the 2020s, on some platforms, a web browser is essential.
#

.if ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "aarch64"
DEPENDS+=	firefox-esr-[0-9]*:../../www/firefox-esr
.endif

.include "../../mk/bsd.pkg.mk"
