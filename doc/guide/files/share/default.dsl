<!DOCTYPE style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN" [
<!ENTITY netbsd.dsl PUBLIC "-//NetBSD//DOCUMENT DocBook DSSSL Stylesheet//EN" CDATA DSSSL>
]>

<!-- $NetBSD: default.dsl,v 1.2 2016/06/11 18:14:42 rillig Exp $ -->

<style-sheet>
  <style-specification use="docbook">
    <style-specification-body>
      <![ %output.print; [
        (element code ($mono-seq$))
      ]]>
    </style-specification-body>
  </style-specification>

  <external-specification id="docbook" document="netbsd.dsl">
</style-sheet>
