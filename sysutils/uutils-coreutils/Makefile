# $NetBSD: Makefile,v 1.4 2026/08/20 12:40:58 pin Exp $

DISTNAME=	coreutils-0.10.0
PKGREVISION=	1
PKGNAME=	uutils-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=uutils/}
GITHUB_PROJECT=	coreutils
GITHUB_TAG=	dba580dc057007bc153098b7a5aac3f0bd9aeea7

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://uutils.github.io/coreutils/
COMMENT=	Cross-platform Rust rewrite of the GNU coreutils
LICENSE=	mit

RUST_REQ=	1.88.0

PROGS+=		arch b2sum base32 base64 basename basenc cat chgrp chmod chown chroot cksum \
		comm cp csplit cut date dd df dir dircolors dirname du echo env expand expr \
		factor false fmt fold groups head hostid hostname id install join kill link ln \
		logname ls md5sum mkdir mkfifo mknod mktemp more mv nice nl nohup nproc numfmt \
		od paste pathchk pinky pr printenv printf ptx pwd readlink realpath rm rmdir \
		seq sha1sum sha224sum sha256sum sha384sum sha512sum shred shuf sleep sort \
		split stat stdbuf stty sum sync tac tail tee test timeout touch tr true \
		truncate tsort tty uname unexpand uniq unlink uptime users vdir wc who whoami \
		yes

INSTALLATION_DIRS+=	uutils-coreutils/bin

CARGO_NO_DEFAULT_FEATURES=	YES
CARGO_FEATURES+=		feat_os_unix

post-install:
.for program in ${PROGS}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils uu-${program}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} coreutils ../uutils-coreutils/bin/${program}
.endfor

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
