# $NetBSD: Makefile,v 1.16 2024/06/13 13:47:02 bsiegert Exp $

DISTNAME=	bulk-test-essential-20230705
PKGREVISION=	11
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
# Limit to only building for the default versions, otherwise this package
# ends up being scanned over 9000 times (despite only supporting a single
# package name).
#
LUA_VERSIONS_ACCEPTED=		${LUA_VERSION_DEFAULT}
MYSQL_VERSIONS_ACCEPTED=	${MYSQL_VERSION_DEFAULT}
PGSQL_VERSIONS_ACCEPTED=	${PGSQL_VERSION_DEFAULT}
PHP_VERSIONS_ACCEPTED=		${PHP_VERSION_DEFAULT}
PKG_APACHE_ACCEPTED=		${PKG_APACHE_DEFAULT}
PKG_JVMS_ACCEPTED=		${_PKG_JVM_DEFAULT}
PYTHON_VERSIONS_ACCEPTED=	${PYTHON_VERSION_DEFAULT}
RUBY_RAILS_ACCEPTED=		${RUBY_RAILS_DEFAULT}
RUBY_VERSIONS_ACCEPTED=		${RUBY_VERSION_DEFAULT}

#
# Essential for binary package usage.
# Required for parts of the NetBSD installer (sysinst) to function.
#
DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin

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
.include "../../lang/ruby/buildlink3.mk"

# FP issues
.if ${MACHINE_ARCH} != "vax"
.  include "../../lang/python/pyversion.mk"
.endif

.include "../../mk/mysql.buildlink3.mk"

# mips: TAS implementation issues
# alpha: locking/membar issues
.if ${MACHINE_ARCH} != "mips" && ${MACHINE_ARCH} != "alpha"
.  include "../../mk/pgsql.buildlink3.mk"
.endif

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
# Essential client packages.
# Long history in pkgsrc. Most of these build even on vax.
#
DEPENDS+=	emacs-nox11-[0-9]*:../../editors/emacs-nox11
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	mutt-[0-9]*:../../mail/mutt
DEPENDS+=	nano-[0-9]*:../../editors/nano
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	screen-[0-9]*:../../misc/screen
DEPENDS+=	vim-[0-9]*:../../editors/vim

#
# Essential server packages.
# Long history in pkgsrc. Most of these build even on vax.
#
DEPENDS+=	apache-[0-9]*:../../www/apache24
DEPENDS+=	dovecot-[0-9]*:../../mail/dovecot2
DEPENDS+=	nginx-[0-9]*:../../www/nginx

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
# Essential desktop packages.
# Important for handling "core" file formats. Long history in pkgsrc.
#

.if ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "aarch64"
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	firefox-esr-[0-9]*:../../www/firefox-esr
DEPENDS+=	libreoffice-[0-9]*:../../misc/libreoffice
.endif

.include "../../mk/bsd.pkg.mk"
