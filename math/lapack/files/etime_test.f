      program main

c
c  $NetBSD: etime_test.f,v 1.1 2010/03/17 21:47:11 dmcmahill Exp $
c
c  Simple program to check if the etime function is available
c
      implicit none

      real cpu
      real etime
      intrinsic etime
      real t_array(2)

      cpu = etime ( t_array )

      write ( *, '(a)' ) ' '
      write ( *, '(a)' ) '  ETIME reports:'
      write ( *, '(a,g14.6)' ) 
     &  '    The current CPU time is       ', cpu
      write ( *, '(a,g14.6)' ) 
     &  '    TARRAY(1) =                   ', t_array(1)
      write ( *, '(a,g14.6)' ) 
     &  '    TARRAY(2) =                   ', t_array(2)

      stop
      end
