# Rust Maintenance Plan

$NetBSD: README.md,v 1.1 2023/10/23 17:10:23 gdt Exp $

This file describes a plan for maintaining rust.  It's logically like
comments in the Makefile.

# Plan

Generally, pkgsrc will update to each minor version (1.x) of rust in
sequence, to enable people to bisect if they have to, and to reduce
pain towards a future, even if theoretical, get-well plan for perhaps
reproducible and from-source build chains.  (It might be that a
version is only in for a few days.)

pkgsrc will in general update rust and rust-bin at the same time.

There will be platforms where rust or rust-bin won't work, because
forward progress and no lossage are obviously incompatible in
practice, at least for now.  We (currently, will evolve) insist on
x86, i386, aarch64, earmv7hf-el working, would really like to see
sparc64 and earmv7hf-el, and hope for powerpc, riscv64, mipsel.  See
https://cdn.netbsd.org/pub/pkgsrc/distfiles/LOCAL_PORTS/rust/
for status.

We will try to stage each update in wip, so that people can test
before it is committed.  These will be wip/rust1NN and wip/rust1NN-bin,
so that N and N+1 can coexist if the 2nd version is being packaged
before pkgsrc is updated to the first.


# Goals

We will attempt to document the bootstrap process such that people who
are not rust experts but have the hardware (or have set up an

Document the testing plan.  Attempt to minimize work while maximizing
safety.
