# $NetBSD: Makefile,v 1.54 2012/05/29 18:14:13 cheusov Exp $

.include "../../sysutils/coreutils/Makefile.common"

PKGREVISION=	1

CONFLICTS=	fileutils-[0-9]* gnuls-[0-9]* linuxls-[0-9]* sh-utils-[0-9]* textutils-[0-9]*

# devel/id-utils installs a 'gid' program, so conflict with it
# databases/geneweb a 'gwc' program, so conflict with it
# graphics/graphviz installs a 'gpr' program, so conflict with it
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
CONFLICTS+=		geneweb-[0-9]*
CONFLICTS+=		graphviz<1.12

INFO_FILES=		yes

# Exclude programs from PLIST which aren't built on a platform.
PLIST_VARS+=		hostid stdbuf
.if ${OPSYS} != "Interix"
PLIST.hostid=		yes
.endif

.include "../../mk/compiler.mk"

.if ${OBJECT_FMT} == "ELF" && \
    (!empty(PKGSRC_COMPILER:Mgcc) || !empty(PKGSRC_COMPILER:Mclang))
PLIST.stdbuf=		yes
.endif

PROGS=	[ base64 basename cat chcon chgrp chmod chown chroot cksum comm \
	cp csplit cut date dd df dir dircolors dirname du hostid echo env \
	expand expr factor false fmt fold groups head id install join kill \
	link ln logname ls md5sum mkdir mkfifo mknod mktemp mv nice nl \
	nohup nproc od paste pathchk pinky pr printenv printf ptx pwd \
	readlink rm rmdir runcon seq sha1sum sha224sum sha256sum sha384sum \
	sha512sum shred shuf sleep sort split stat stdbuf stty sum sync tac \
	tail tee test timeout touch tr true truncate tsort tty uname \
	unexpand uniq unlink uptime users vdir wc who whoami yes

INSTALLATION_DIRS+=	gnu/bin

post-install:
	set -e; \
	cd ${DESTDIR}${PREFIX}/gnu/bin; \
	for p in ${PROGS}; do \
	   if ${TEST} -x "../../bin/g$${p}"; then \
	      ln -f -s "../../bin/g$${p}" "$${p}"; \
	   fi; \
	done

#CONFIGURE_ARGS+=	--enable-install-program=su
#.if ${OPSYS} == "NetBSD" ||  ${OPSYS} == "FreeBSD" || \
#  ${OPSYS} == "OpenBSD"
#MAKE_FLAGS+=		setuid_root_mode=a=rx
#MESSAGE_SRC=		${.CURDIR}/MESSAGE.gsu
#MESSAGE_SUBST+=	OPSYS=${OPSYS:Q}
#.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
