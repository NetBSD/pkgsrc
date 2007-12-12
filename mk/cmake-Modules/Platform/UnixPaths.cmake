SET(CMAKE_SYSTEM_INCLUDE_PATH ${CMAKE_SYSTEM_INCLUDE_PATH}
  # Standard
  $ENV{BUILDLINK_DIR}/include /include /usr/include 

  )

SET(CMAKE_SYSTEM_LIBRARY_PATH ${CMAKE_SYSTEM_LIBRARY_PATH}
  # Standard
  $ENV{BUILDLINK_DIR}/lib /lib     /usr/lib
  )

SET(CMAKE_SYSTEM_PROGRAM_PATH ${CMAKE_SYSTEM_PROGRAM_PATH}
  /bin /usr/bin /usr/local/bin /usr/pkg/bin /sbin
  )
