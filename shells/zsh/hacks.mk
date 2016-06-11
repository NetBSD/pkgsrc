# $NetBSD: hacks.mk,v 1.4 2016/06/11 23:34:07 dholland Exp $

.if !defined(ZSH_HACKS_MK)
ZSH_HACKS_MK=	defined

### [Sun Dec 21 02:00:19 JST 2008 : uebayasi]
### Built a dynamically linked "zsh" binary on NetBSD systems which use
### dynamically linked binaries on the root filesystem. The binary will
### only depend on the run-time link-editor and shared libraries on the
### root filesystem. We use "-rpath" below by purpose because the
### buildlink 3 framework won't filter it out.
NETBSD_SHLINKER=	/libexec/ld.elf_so	# XXX move elsewhere
NETBSD_SHLIBDIR=	/lib			# XXX move elsewhere
.if ${OPSYS} == "NetBSD" && \
      defined(OBJECT_FMT) && ${OBJECT_FMT} == "ELF" && \
      defined(MKDYNAMICROOT) && ${MKDYNAMICROOT} != "no" && \
      defined(NETBSD_SHLINKER) && exists(${NETBSD_SHLINKER}) && \
      defined(NETBSD_SHLIBDIR) && exists(${NETBSD_SHLIBDIR})
PKG_HACKS+=	static-dynamic
_ZSH_LINKAGE.static.BUILDLINK_PASSTHRU_RPATHDIRS=	${NETBSD_SHLIBDIR}
_ZSH_LINKAGE.static.LDFLAGS=	-Wl,-dynamic-linker=${NETBSD_SHLINKER} -Wl,-R${NETBSD_SHLIBDIR}
.endif

.endif  # ZSH_HACKS_MK
