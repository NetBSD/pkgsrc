# $NetBSD: type.mk,v 1.2 2020/05/18 16:33:44 wiz Exp $
# 
# This file determines the type of rust package to use -
# binary (as via rustup) or a source bootstrap.
#
# Rust only publishes binaries for specific platforms in specific
# tiers.
#
# === User-settable variables ===
#
# RUST_TYPE
#	The preferred Rust type to use.
#
#	Possible values: src bin
#	Default: src

.if !defined(RUST_TYPE)
.  include "../../mk/bsd.fast.prefs.mk"

# The Rust bootstrapping process is often particularly slow
# and unreliable on NetBSD due to ld.so bugs
.  if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
RUST_TYPE?=	bin
.  else
RUST_TYPE?=	src
.  endif

.endif # !defined(RUST_TYPE)
